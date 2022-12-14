#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long L[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //string bla = "What are you doing while sending \"What are you doing at the end of the world? Are you busy? Will you save us?\"? Are you busy? Will you send \"What are you doing at the end of the world? Are you busy? Will you save us?\"?";
    //cout<<bla.size()<<endl;
    string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    L[0] = f0.size();
    string bla1 = "What are you doing while sending \"";
    string bla2 = "\"? Are you busy? Will you send \"";
    string bla3 = "\"?";
    for (int i=1;i<100;i++){
        L[i] = L[i-1]*2 + bla1.size()+bla2.size()+bla3.size();
        if (L[i]>1e18){
            L[i]=1e18+2;
            for (int j=i+1;j<=100000;j++)L[j]=L[i];
            break;
        }
    }
    int t;
    cin>>t;
    while(t--) {
        ll k, n;
        cin >> n >> k;
        int cur = n;
        while (1) {
            if (n==0){
                if (k<=f0.size())cout<<f0[k-1];
                else cout<<'.';
                break;
            }
            if (k <= bla1.size()) {
                cout << bla1[k - 1] ;
                break;
            }
            k -= bla1.size();
            if (k <= L[n - 1]) {
                n--;
                continue;
            }
            k-=L[n-1];
            if (k <= bla2.size()) {
                cout << bla2[k - 1] ;
                break;
            }
            k -= bla2.size();
            if (k <= L[n - 1]) {
                n--;
                continue;
            }
            k-=L[n-1];
            if (k <= bla3.size()) {
                cout << bla3[k - 1] ;
                break;
            }
            k -= bla3.size();
            cout<<'.';
            break;
        }
    }
}