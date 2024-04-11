#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int M = 100050, N = M;

int n;
bool p[M];
int mu[M], pm[M], pms;
bool in[N];
vector<P> res;


void get_mobius_and_sieve(){
    mu[1] = 1;
    fill(p, p + M, true);
    pms = 0;
    for(int i = 2; i < M; i++){
        if(p[i]){
            pm[pms++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = false;
            if(i % pm[j] == 0){
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
}

int main(){
    get_mobius_and_sieve();
    cin >> n;
    fill(in, in + N, true);

    for(int i = pms - 1; i >= 0; i--){
//        cout << i << endl;
        vector<int> rest;
        for(int j = pm[i]; j <= n; j += pm[i]){
            if(in[j]) rest.push_back(j);
        }
        if(rest.size() == 1) continue;
        if(rest.size() % 2 == 1) rest.erase(lower_bound(rest.begin(), rest.end(), 2 * pm[i]));
        for(int j = 0; j < rest.size(); j += 2){
            res.push_back({rest[j], rest[j+1]});
            in[rest[j]] = in[rest[j+1]] = false;
        }
    }
    printf("%d\n", res.size());
    for(auto p : res){
        printf("%d %d\n", p.first, p.second);
    }
}