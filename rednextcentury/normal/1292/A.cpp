#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool is[5][1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    int numCol=0,numDiag=0;
    while(q--) {
        int r,c;
        cin>>r>>c;
        r--;
        is[r][c]=1-is[r][c];
        if (is[r][c]==0){
            if (is[!r][c])numCol--;
            if (is[!r][c+1])numDiag--;
            if (is[!r][c-1])numDiag--;
        } else {
            if (is[!r][c])numCol++;
            if (is[!r][c+1])numDiag++;
            if (is[!r][c-1])numDiag++;
        }
        if (numDiag+numCol==0){
            cout<<"Yes\n";
        } else cout<<"No\n";
    }
}