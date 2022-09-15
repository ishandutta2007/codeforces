#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
void solve();

#define pb push_back

typedef long long li;
typedef vector<int> vi;
//typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
struct pi{
    int first,second;
    pi(){}
    pi(int a,int b):first(a),second(b){}
    pi operator -(const pi& b){
        return pi(first-b.first,second-b.second);
    }
    bool operator !=(const pi& b){
        return first!=b.first || second != b.second;
    }

    int abs(){
        return first*first+second*second;
    }
};
bool is_line(pi&a,pi&b,pi&c){
    pi t=(b-a);
    pi u=c-a;
    return t.first*u.second == t.second*u.first;
}
bool is_square(pi&a,pi&b,pi&c,pi& d){
    if(is_line(a,b,c))
        return false;
    if((b-a)!=(c-d))
        return false;
     if((b-a).first*(d-a).first!=-((b-a).second)*((d-a).second))
        return false;
    if(abs((b-a).first)!=abs((d-a).second))
        return false;
    if(abs((b-a).second)!=abs((d-a).first))
        return false;

    return true;
}
bool is_rect(pi&a,pi&b,pi&c,pi&d){
    if(is_line(a,b,c))
        return false;
    if(b-a!=c-d)
        return false;

    if((b-a).first*(d-a).first!=-((b-a).second)*((d-a).second))
        return false;

    return true;
}

void solve() {
    pi p[10];
    for(int i=0;i<8;++i){
        cin>>p[i].first>>p[i].second;
    }
    for(int a=0;a<8;++a){

        for(int b=0;b<8;++b){
            if(a==b)
                continue;

            for(int c=0;c<8;++c){
                if(b==c || a==c)
                    continue;
                for(int d=0;d<8;++d){
                    if(c==d || a==d || b==d)
                        continue;
                    if(!is_square(p[a],p[b],p[c],p[d]))
                        continue;
                    for(int e=0;e<8;++e){
                        if(a==e ||b==e||c==e||d==e)
                            continue;


                        for(int f=0;f<8;++f){
                            if(a==f || b==f || c==f || d==f || e==f){
                                continue;
                            }

                            for(int g=0;g<8;++g){
                                if(a==g || b==g || c==g || d==g || e==g || f==g)
                                    continue;

                                for(int h=0;h<8;++h){
                                    if(a==h || b==h || c==h || d==h || e==h || f==h)
                                        continue;
                                    if(is_rect(p[e],p[f],p[g],p[h])){
                                        cout<<"YES\n";
                                        cout<<++a<<' '<<++b<<' '<<++c<<' '<<++d<<endl;
                                        cout<<++e<<' '<<++f<<' '<<++g<<' '<<++h<<endl;
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"NO";
}