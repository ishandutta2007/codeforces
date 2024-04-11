#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)cin>>a[i];
        ll last = a[1];
        int L = 2, R = n;
        int turn = 1;
        int total=1, A=a[1], B=0;
        while(1){
            if (L>R) break;
            if (turn==1){
                ll cur=0;
                while(R>=L && cur<=last){
                    cur+=a[R];
                    R--;
                }
                B+=cur;
                last=cur;
                total++;
            } else {
                ll cur=0;
                while(L<=R && cur<=last){
                    cur+=a[L];
                    L++;
                }
                A+=cur;
                last=cur;
                total++;
            }
            turn = 1- turn;
        }
        cout<<total<<' '<<A<<' '<<B<<endl;
    }
}