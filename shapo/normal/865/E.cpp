#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF = 1ll << 56;

int
hex_from(char c)
{
    return (c >= '0' && c <= '9') ? c - '0' : c - 'a' + 10;
}

char
hex_to(int x)
{
    return (x <= 9) ? 'a' + (x - 10) : x + '0';
}

void
gen_comb(size_t n, size_t k, vector<size_t>& state, vector<vector<size_t>>& all_combs)
{
    if (state.size() == k) {
        all_combs.push_back(state);
        return;
    }
    for (size_t min_next = state.empty() ? 0 : state.back() + 1; min_next < n; ++min_next) {
        state.push_back(min_next);
        gen_comb(n, k, state, all_combs);
        state.pop_back();
    }
}

ll
find_ans(const vector<int>& diff, const vector<size_t>& carries)
{
    vector<int> dig_diff = diff;
    for (int pos_carry : carries) {
        dig_diff[pos_carry] -= 16;
        dig_diff[pos_carry + 1]++;
    }
    size_t n = diff.size();
    vector<ll> dp(1 << n, INF);
    vector<int> psum(1 << n, 0);
    for (size_t h_bit = 0; h_bit < n; ++h_bit) {
        for (size_t mask = (1u << h_bit); mask < (1u << (h_bit + 1)); ++mask) {
            psum[mask] = psum[mask ^ (1 << h_bit)] + dig_diff[h_bit];
        }
    }
    if (psum.back() != 0) {
        return INF;
    }
    dp[0] = (1ll << (4 * n)) - 1;
    for (size_t mask = 0; mask < (1u << n); ++mask) {
        if (psum[mask] < 0 || psum[mask] >= 16) {
            continue;
        }
        for (size_t pos = 0; pos < n; ++pos) {
            if (mask & (1 << pos)) {
                continue;
            }
            // set digit at position `pos` to `psum[mask]`
            ll new_val = (dp[mask] & ~(15ll << (4 * pos))) | (ll(psum[mask]) << (4 * pos));
            dp[mask | (1 << pos)] = min(dp[mask | (1 << pos)], new_val);
        }
    }
    return dp.back();
}

int
main()
{
    string s;
    cin >> s;
    size_t n = s.size();
    vector<int> diff(n);
    for (size_t i = 0; i < n; ++i) {
        diff[n - i - 1] = hex_from(s[i]);
    }
    auto sum = accumulate(diff.begin(), diff.end(), 0);
    if (sum % 15 != 0) {
        cout << "NO\n";
        return 0;
    }
    auto n_carry = sum / 15;
    vector<vector<size_t>> all_combs;
    vector<size_t> comb; // temp
    gen_comb(n - 1, n_carry, comb, all_combs);
    ll ans = INF;
    for (const auto& comb : all_combs) {
        ans = min(ans, find_ans(diff, comb));
    }
    if (ans == INF) {
        cout << "NO\n";
    } else {
        cout << hex << setw(n) << right << setfill('0') << ans << '\n';
    }
    return 0;
}