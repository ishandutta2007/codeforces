#include <bitset>
#include <vector>
#include <cassert>

/* Accepts a collection of integers with sum at most MAX_SUM.
 * Computes its set of subset sums in O(MAX_SUM * sqrt(sum) / MACHINE_WORD_SIZE)
 */
template<int MAX_SUM, typename InputIterator>
std::bitset<MAX_SUM + 1> subset_sum(InputIterator first, InputIterator last) {
    int sum = accumulate(first, last, 0);
    assert(sum <= MAX_SUM);

    static std::vector<int> count(MAX_SUM + 1);

    for (InputIterator iter = first; iter != last; iter++)
        count[*iter]++;

    std::bitset<MAX_SUM + 1> result;
    result[0] = 1;

    for (int val = 1; val <= sum; val++) {
        if (count[val] > 2) {
            int pairs = (count[val] - 1) / 2;
            count[2 * val] += pairs;
            count[val] -= 2 * pairs;
        }

        while (count[val]) {
            result |= result << val;
            count[val]--;
        }
    }

    return result;
}

// Problem: https://codeforces.com/problemset/problem/755/F

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// {{{ misc/subset_sum.cpp }}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> giver(N);

    for (int i = 0; i < N; i++) {
        cin >> giver[i];
        --giver[i];
    }

    vector<int> cycle_lengths;

    vector<bool> visited(N);
    for (int i = 0; i < N; i++) {
        if (visited[i])
            continue;

        int length = 0;
        for (int t = i; !visited[t]; t = giver[t]) {
            visited[t] = true;
            length++;
        }

        cycle_lengths.push_back(length);
    }

    auto sums = subset_sum<1000000>(cycle_lengths.begin(), cycle_lengths.end());

    int minimum = K + !sums[K];

    int twos = 0, ones = 0;

    for (int length : cycle_lengths) {
        twos += length / 2;
        ones += length & 1;
    }

    int maximum = 2 * min(K, twos) + min(ones, K - min(K, twos));

    printf("%d %d\n", minimum, maximum);

    return 0;
}