#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 200005

//int nums[MAX_N];

int main(){
    int N, M;
    cin >> N >> M;

    ll soFar = 0;
    ll prev = soFar;

    for(int i=0; i<N; i++){
        ll x;
        cin >> x;
        soFar += x;

        cout << soFar/M - prev/M << " ";

        prev = soFar;
    }

    return 0;
}