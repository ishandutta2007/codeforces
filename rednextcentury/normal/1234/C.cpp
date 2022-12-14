#include <bits/stdc++.h>
using namespace std;
set<int> cur;
deque<int> q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a[2];
        cin>>a[0]>>a[1];
        int last = 1; // up
        // 2 is down
        // 3 is both
        // 0 is none
        for (int i=0;i<n;i++) {
            char l = a[0][i];
            char r = a[1][i];
            int L,R;
            if (l>='3')L=1;
            else L=0;
            if (r>='3')R=1;
            else R=0;
            if (L==0 && R==0) {
                continue;
            } else if (L==1 && R==0) {
                if (last==2 || last==3)last=2;
                else last=0;
            } else if (L==0 && R==1) {
                if (last==1 || last==3)last=1;
                else last=0;
            } else if (L==1 && R==1) {
                if (last==1)last=2;
                else if (last==2) last=1;
                else if (last==3) last=3;
            }
            if (last==0)break;
        }
        if (last==2 || last==3) {
            cout<<"YES"<<endl;
        } else cout<<"NO"<<endl;
    }
}