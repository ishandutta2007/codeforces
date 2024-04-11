#include<bits/stdc++.h>
using namespace std;
#define ll long long
int four[] = {2, 4, 1, 3};
int five[] = {2, 5, 3, 1, 4};
int six[] = {2, 4, 6, 3, 1, 5};
int seven[] = {2, 4, 7, 5, 1, 3, 6};
bool can[1001];
int last[1001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int val[] = {4,5,6,7};
    can[0]=1;
    for (int i=4;i<=1000;i++){
        for (int j=0;j<4;j++){
            if (val[j]>i)continue;
            can[i]=can[i]|can[i-val[j]];
            if (can[i-val[j]]) last[i] = val[j];
        }
        if (!can[i])cout<<i<<endl;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if (n<4)cout<<-1<<endl;
        else{
            vector<int> path;
            int v = n;
            while(1){
                path.push_back(last[v]);
                v -= last[v];
                if (v==0)break;
            }
            reverse(path.begin(),path.end());
            int cur = 1;
            vector<int> ret;
            for (auto x:path){
                if (x==4){
                    for (int i=0;i<4;i++) ret.push_back(cur+four[i]-1);
                    cur+=4;
                } else if (x==5){
                    for (int i=0;i<x;i++) ret.push_back(cur+five[i]-1);
                    cur+=x;
                } else if (x==6){
                    for (int i=0;i<x;i++) ret.push_back(cur+six[i]-1);
                    cur+=x;
                } else if (x==7){
for (int i=0;i<x;i++) ret.push_back(cur+seven[i]-1);
                    cur+=x;
                }
            }
            for (auto x:ret)cout<<x<<' ';
            cout<<endl;
        }
    }
}