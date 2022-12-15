#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 7;
const int k_Val = 3e5 + 7;

int a[k_N];
int largest_prime[k_Val];
vector<int> add[k_Val];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(long long i = 2; i < k_Val; ++i){
        if(!largest_prime[i]){
            largest_prime[i] = i;

            for(long long j = i * i; j < k_Val; j += i)
                if(!largest_prime[j])
                    largest_prime[j] = i;
        }
    }

    for(int i = 0; i < n; ++i){
        while(a[i] != 1){
            int d = largest_prime[a[i]], power = 1;
            while(a[i] % d == 0){
                a[i] /= d;
                power *= d;
            }

            add[d].push_back(power);
        }
    }

    long long answer = 1;
    for(int i = 2; i < k_Val; ++i){
        if(add[i].size() < n - 1)
            continue;

        sort(add[i].begin(), add[i].end());

        answer *= add[i][add[i].size() - (n - 1)];
    }

    cout << answer << "\n";
}