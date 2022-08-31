#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=1e5+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
string s;int fk;
int main(){
    for(;;){
        cout<<"next 0 1"<<endl;
        cout.flush();
        cin>>fk;getline(cin,s);
        cout<<"next 0"<<endl;
        cout.flush();
        cin>>fk;getline(cin,s);

        int tmp=0;
        while(s[tmp]!='0')++tmp;
        if(tmp!=(int)s.length()-1&&s[tmp+1]=='1')break;
    }
    
    for(;;){
        cout<<"next 0 2"<<endl;
        cout.flush();
        cin>>fk;getline(cin,s);

        int tmp=0;
        while(s[tmp]!='0')++tmp;
        if(tmp!=(int)s.length()-1&&s[tmp+1]=='1')break;
    }

    for(;;){
        cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
        cout.flush();
        cin>>fk;getline(cin,s);

        if(fk==1)break;
    }
    cout<<"done"<<endl;
    return 0;
}