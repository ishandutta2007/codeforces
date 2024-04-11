#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<char, char> pi;
typedef pair<li, li> pli;
#define mp make_pair
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}

char ans[200][200];
void solve(){
    int a,b,c,d,n,x[100];
    cin>>a>>b>>c>>d>>n;
    cout<<"YES\n";
    for(int i=0;i<n;++i){
        cin>>x[i];
    }
    for(int i=0,e=max(b,d);i<e;++i){
        for(int j=0,s=c+a;j<s;++j)
            ans[i][j]='.';
    }
    int add=1;
    if(a%2){
        add=-1;
    }
    int uzhe_stoit=0;
    char part='a';
    for(int j=0;j<a;++j){
        for(int i=((add==1)?0:b-1),k=((add==1)?b:-1);i!=k;i+=add){
            ans[i][j]=part;
            ++uzhe_stoit;
            if(uzhe_stoit==x[part-'a']){
                ++part;
                uzhe_stoit=0;
            }
        }
        add*=-1;
    }
    for(int j=0;j<c;++j){
        for(int i=((add==1)?0:d-1),k=((add==1)?d:-1);i!=k;i+=add){
            ans[i][a+j]=part;
            ++uzhe_stoit;
            if(uzhe_stoit==x[part-'a']){
                ++part;
                uzhe_stoit=0;
            }
        }
        add*=-1;
    }
    for(int i=0,e=max(b,d);i<e;++i){
        for(int j=0,s=c+a;j<s;++j){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}