#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 35

string resp;

int query(int y){
    cout << y << "\n";
    fflush(stdout);

    int resp;
    cin >> resp;
    if(resp == 0 || resp == -2){
        exit(0);
    }

    return resp;
}

bool correct[MAX_N];

int main(){
    int m, n;
    cin >> m >> n;

    for(int i=0; i<n; i++){
        int ans = query(m);
        correct[i] = (ans==1) ? true : false;
    }

    int left = 1;
    int right = m-1;
    int cnt = 0;
    while(left <= right){
        int mid = (left+right)/2;
        
        bool resp = (query(mid)==1);
        if(resp == correct[cnt]){
            right = mid-1;
        } else{
            left = mid+1;
        }
        cnt = (cnt+1)%n;
    }

    return 0;
}