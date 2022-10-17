#include <vector>

struct knuth_morris_pratt {
    int SZ;
    std::vector<int> pattern;
    std::vector<int> suffix_link;

    int append(int matched, int c) const {
        while (matched > 0 && pattern[matched] != c)
            matched = suffix_link[matched];
        return matched + int(pattern[matched] == c);
    }

    knuth_morris_pratt() : SZ(0) { }

    template<typename InputIterator>
    knuth_morris_pratt(InputIterator begin, InputIterator end) {
        initialize(begin, end);
    }

    template<typename InputIterator>
    void initialize(InputIterator begin, InputIterator end) {
        pattern.resize(end - begin);
        copy(begin, end, pattern.begin());

        SZ = int(pattern.size());
        suffix_link.resize(SZ + 1);

        for (int matched = 1; matched < SZ; matched++)
            suffix_link[matched + 1] = append(suffix_link[matched], pattern[matched]);
    }

    template<typename InputIterator, typename F>
    void find_matches(InputIterator begin, InputIterator end, F consume) const {
        int i = 0;
        int matched = 0;
        for (InputIterator iter = begin; iter != end; iter++, i++) {
            matched = append(matched, *iter);
            if (matched == SZ) {
                consume(i - SZ + 1);
                matched = suffix_link[matched];
            }
        }
    }

    template<typename InputIterator>
    int count_matches(InputIterator begin, InputIterator end) const {
        int count = 0;
        find_matches(begin, end, [&](__attribute((unused))int index) { count++; });
        return count;
    }

    template<typename InputIterator>
    std::vector<int> indices_of_matches(InputIterator begin, InputIterator end) const {
        std::vector<int> indices;
        find_matches(begin, end, [&](int index) { indices.push_back(index); });
        return indices;
    }
};

#include <vector>
#include <numeric>
#include <algorithm>

namespace stable_counting_sort {
    template<typename T = int>
    T identity(const T& t) { return t; }

    template<typename T_extract_key = int(*)(const int&)>
    const std::vector<int>& permutation(int SZ, int MAX_KEY,
			const T_extract_key &extract_key = identity) {

        static std::vector<int> p;
        p.resize(SZ);

        if (SZ < 256) {
            std::iota(p.begin(), p.end(), 0);
            std::sort(p.begin(), p.end(), [&](int a, int b) {
                return extract_key(a) < extract_key(b);
            });
        } else {
            static std::vector<int> count;
            count.assign(MAX_KEY, 0);
            for (int i = 0; i < SZ; i++)
                count[extract_key(i)]++;
            for (int i = 0; i < MAX_KEY - 1; i++)
                count[i + 1] += count[i];
            for (int i = SZ - 1; i >= 0; i--)
                p[--count[extract_key(i)]] = i;
        }

        return p;
    }
}

// {{{ miscellaneous/stable_counting_sort.cpp }}}

#include <array>
#include <vector>
#include <cassert>

template<int MIN_CHAR, int SIGMA>
struct suffix_automaton {
    struct state {
        int len = 0;
        int suffix_link = -1;
        int first_end_pos = -1;
        std::array<int, SIGMA> transitions;
        state() { transitions.fill(-1); }
    };

    int SZ, last;
    std::vector<state> data;
    std::vector<bool> is_clone;

    const state& operator [] (int loc) const { return data[loc]; }

    int create_state(state s = {}) {
        data.push_back(s);
        is_clone.push_back(s.len != 0);
        return int(data.size()) - 1;
    }

    suffix_automaton() : SZ(0) { last = create_state(); }

    template<typename InputIterator>
    suffix_automaton(InputIterator begin, InputIterator end) {
        initialize(begin, end);
    }

    template<typename InputIterator>
    void initialize(InputIterator begin, InputIterator end) {
        SZ = 0;
        data.clear();
        is_clone.clear();
        last = create_state();

        for (InputIterator iter = begin; iter != end; iter++)
            append(*iter);
        initialize_auxiliary_data();
    }

    void append(int c) {
        assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
        c -= MIN_CHAR;

        int p = last;

        last = create_state();
        data[last].first_end_pos = SZ;
        data[last].len = ++SZ;

        while (p != -1 && data[p].transitions[c] == -1) {
            data[p].transitions[c] = last;
            p = data[p].suffix_link;
        }

        if (p == -1) {
            data[last].suffix_link = 0;
            return;
        }

        int q = data[p].transitions[c];
        if (data[q].len - data[p].len == 1) {
            data[last].suffix_link = q;
            return;
        }

        int pc = create_state(data[q]);
        data[pc].len = data[p].len + 1;

        while (p != -1 && data[p].transitions[c] == q) {
            data[p].transitions[c] = pc;
            p = data[p].suffix_link;
        }

        data[q].suffix_link = pc;
        data[last].suffix_link = pc;
    }

    std::vector<int> reverse_length_order;
    std::vector<int> ct_end_pos;
    void initialize_auxiliary_data() {
        reverse_length_order = stable_counting_sort::permutation(
                int(data.size()), SZ + 1, [&](int loc) { return SZ - data[loc].len; });

        ct_end_pos.assign(data.size(), 0);
        for (int loc : reverse_length_order) {
            if (loc) {
                ct_end_pos[loc] += !is_clone[loc];
                ct_end_pos[data[loc].suffix_link] += ct_end_pos[loc];
            } else ct_end_pos[loc] = 0;
        }
    }

    int transition(int loc, int c) const {
        assert(loc != -1 && MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
        return data[loc].transitions[c - MIN_CHAR];
    }

    template<typename InputIterator>
    int state_associated_with(InputIterator begin, InputIterator end) const {
        int loc = 0;
        for (auto iter = begin; iter != end && loc != -1; iter++)
            loc = transition(loc, *iter);
        return loc;
    }

    template<typename InputIterator>
    int first_occurence(InputIterator begin, InputIterator end) const {
        int loc = state_associated_with(begin, end);
        return loc == -1 ? -1 : data[loc].first_end_pos - distance(begin, end) + 1;
    }

    template<typename InputIterator>
    int count_occurences(InputIterator begin, InputIterator end) const {
        int loc = state_associated_with(begin, end);
        return loc == -1 ? 0 : ct_end_pos[loc];
    }
};

// {{{ strings/suffix_automaton.cpp }}}
// {{{ strings/knuth_morris_pratt.cpp }}}

#include <vector>
#include <cmath>

template<int MIN_CHAR, int SIGMA>
struct mutable_string {
    int SZ;
    std::vector<int> data;

    int BLOCK_SZ;
    std::vector<suffix_automaton<MIN_CHAR, SIGMA>> blocks;

    template<typename InputIterator>
    mutable_string(InputIterator begin, InputIterator end) : data(begin, end) {
        SZ = int(data.size());
        BLOCK_SZ = int(ceil(std::sqrt(data.size())));
        for (int i = 0; i < SZ; i += BLOCK_SZ)
            blocks.emplace_back(data.begin() + i, data.begin() + std::min(i + BLOCK_SZ, SZ));
    }

    std::vector<int>::iterator block_start(int block_id) {
        return data.begin() + std::min(block_id * BLOCK_SZ, SZ);
    }
    std::vector<int>::const_iterator block_start(int block_id) const {
        return data.begin() + std::min(block_id * BLOCK_SZ, SZ);
    }

    // O(sqrt(SZ))
    void assign(int i, int c) {
        data[i] = c;
        int block_id = i / BLOCK_SZ;
        blocks[block_id].initialize(block_start(block_id), block_start(block_id + 1));
    }

    // O(min(|end - begin| * sqrt(SZ), |end - begin| + len))
    template<typename InputIterator>
    int count_matches_in_substring(InputIterator begin, InputIterator end, int L, int R) const {
        static knuth_morris_pratt kmp;
        kmp.initialize(begin, end);

        int first_block_id = (L + BLOCK_SZ - 1) / BLOCK_SZ;
        int last_block_id  = R / BLOCK_SZ;

        int expected_work =
            first_block_id * BLOCK_SZ - L
            + (last_block_id - first_block_id) * 3 * kmp.SZ
            + R - last_block_id * BLOCK_SZ;

        if (first_block_id >= last_block_id || kmp.SZ > BLOCK_SZ || 3 * expected_work >= (R - L))
            return kmp.count_matches(data.begin() + L, data.begin() + R);

        int count = 0;

        count += kmp.count_matches(data.begin() + L, block_start(first_block_id) + kmp.SZ - 1);

        for (int block_id = first_block_id; block_id < last_block_id; block_id++) {
            count += blocks[block_id].count_occurences(begin, end);

            if (block_id != first_block_id) {
                auto boundary = block_start(block_id);
                count += kmp.count_matches(boundary - kmp.SZ + 1, boundary + kmp.SZ - 1);
            }
        }

        count += kmp.count_matches(block_start(last_block_id) - kmp.SZ + 1, data.begin() + R);

        return count;
    }

    template<typename InputIterator>
    int count_matches(InputIterator begin, InputIterator end) const {
        return count_matches_in_substring(begin, end, 0, SZ);
    }
};

// Problem: https://codeforces.com/contest/914/problem/F

#include <iostream>
using namespace std;

// {{{ strings/mutable_string.cpp }}}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string init;
    cin >> init;

    mutable_string<'a', 26> s(init.begin(), init.end());

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;

        if (t == 1) {
            int i;
            char c;
            cin >> i >> c;

            s.assign(i - 1, c);
        } else {
            int l, r;
            string y;
            cin >> l >> r >> y;

            cout << s.count_matches_in_substring(y.begin(), y.end(), l - 1, r) << "\n";
        }
    }
}