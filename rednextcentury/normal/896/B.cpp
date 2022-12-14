#include<bits/stdc++.h>
using namespace std;
#define ll long long
int L[1000000];
int R[1000000];
int main()
{
    int n,m,c;
    cin>>n>>m>>c;
    int A=0,B=0;
    int lim = c/2;
    while(m--){
        int x;
        cin>>x;
        if (x<=lim) {
            int loc=-1;
            for (int j=0;j<A;j++) {
                if (L[j]>x){
                    loc=j;
                    break;
                }
            }
            if (loc==-1)loc=A++;
            L[loc]=x;
            cout<<loc+1<<endl;
        } else {
            int loc=-1;
            for (int j=0;j<B;j++) {
                if (R[j]<x){
                    loc=j;
                    break;
                }
            }
            if (loc==-1)loc=B++;
            R[loc]=x;
            cout<<n-loc<<endl;
        }
        if (A+B==n)break;
    }
}