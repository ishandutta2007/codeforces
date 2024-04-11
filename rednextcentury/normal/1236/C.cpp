#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ret[1000000];
vector<int> vec[1000000];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int cur=1;
    for (int i=1;i<=n;i++) {
        int op = 1 , dir = 1;
        if (i%2==0)op=n,dir=-1;
        for (int j=cur;j<cur+n;j++) {
            ret[j]=op;
            op+=dir;
        }
        cur+=n;
    }
    for (int i=1;i<cur;i++) {
        vec[ret[i]].push_back(i);
    }
    for (int i=1;i<=n;i++){
        for (auto x:vec[i])cout<<x<<' ';
        cout<<endl;
    }

}