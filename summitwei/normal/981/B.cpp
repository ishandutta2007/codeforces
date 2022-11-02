#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<vector<long long>> vvll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<int, long>> vpil;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef long long ll;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<bool>> vvb;
typedef set<int> si;
#define INF 100000000
#define MOD 257

int mod(int a, int b){
    return ((a % b) + b) % b;
}

int main(){
    int n;
    cin >> n;
    vpil elems1(n);
    for(int i=0; i<n; i++){
        cin >> elems1[i].first >> elems1[i].second;
    }

    int m;
    cin >> m;
    vpil elems2(m);
    for(int i=0; i<m; i++){
        cin >> elems2[i].first >> elems2[i].second;
    }

    sort(elems1.begin(), elems1.end());
    sort(elems2.begin(), elems2.end());

    int a=0, b=0;
    ll totalSum = 0;
    while(a < n || b < m){
        if(a == n){
            totalSum += elems2[b].second;
            b++;
        } else if(b == m){
            totalSum += elems1[a].second;
            a++;
        } else{
            if(elems1[a].first > elems2[b].first){
                totalSum += elems2[b].second;
                b++;
            } else if(elems1[a].first < elems2[b].first){
                totalSum += elems1[a].second;
                a++;
            } else{
                if(elems1[a].second > elems2[b].second){
                    totalSum += elems1[a].second;
                    a++;
                    b++;
                } else{
                    totalSum += elems2[b].second;
                    a++;
                    b++;
                }
            }
        }
    }

    cout << totalSum;
    return 0;
}