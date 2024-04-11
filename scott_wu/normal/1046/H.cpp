#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int LETTERS = 26;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string str;
    map<int, int> freq;

    for (int i = 0; i < N; i++) {
        cin >> str;
        int mask = 0;

        for (char c : str)
            mask ^= 1 << (c - 'a');

        freq[mask]++;
    }

    long long total = 0;

    for (pair<int, int> p : freq) {
        int mask = p.first;
        total += (long long) freq[mask] * (freq[mask] - 1);

        for (int i = 0; i < LETTERS; i++)
            if (freq.count(mask ^ 1 << i))
                total += (long long) freq[mask] * freq[mask ^ 1 << i];
    }

    cout << total / 2 << '\n';
}