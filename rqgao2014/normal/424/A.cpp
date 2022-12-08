#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#define sqr(x) (x)*(x)
#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
using namespace std;

int tot=0;

int main()
{
    int n;
    char a[1001];
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++){
        if(a[i]=='x') tot++; else tot--;
    }
    if(tot>0){
        cout<<tot/2<<endl;
        for(int i=0;i<n&&tot!=0;i++)
            if(a[i]=='x') {a[i]='X';tot-=2;}
    }
    else if(tot<0){
        cout<<-tot/2<<endl;
        for(int i=0;i<n&&tot!=0;i++)
            if(a[i]=='X') {a[i]='x';tot+=2;}
    }
    else cout<<0<<endl;
    cout<<a<<endl;
}