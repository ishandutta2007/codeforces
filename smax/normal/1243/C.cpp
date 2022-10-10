#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];
vector<int> primeSet;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    memset(prime, true, sizeof(prime));

    for (int p=2; p<=1000000; p++)
        if (prime[p]) {
            primeSet.push_back(p);
            if (p <= 1000)
                for (int i=p*p; i<=1000000; i+=p)
                    prime[i] = false;
        }

    long long n;
    cin >> n;

    long long num = n;
    unordered_set<long long> primeDiv;
    for (int p : primeSet)
        while (num % p == 0) {
            num /= p;
            primeDiv.insert(p);
        }
    if (num > 1)
        primeDiv.insert(num);

    if (primeDiv.size() > 1)
        cout << "1\n";
    else if (primeDiv.empty())
        cout << n << "\n";
    else
        cout << *primeDiv.begin() << "\n";

    return 0;
}