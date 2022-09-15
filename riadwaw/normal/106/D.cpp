#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <math.h>
#include <sstream>
#include <complex>
#include <string.h>
#include <algorithm>
using namespace std;
 
void solve(); 
#define mp make_pair
#define pb push_back
typedef int fknmain;
typedef long long int li;
/**
 CAUTION Is int really int?
 * 
 Real solution after main function
 */
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;
 
fknmain main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
    #define LL "%lld"
#else
    #define LL "%I64d"
#endif
#ifndef int
    #define INT "%d"
#else
    #define INT LL
#endif
    solve();
    return 0;
}

char s[1111][1111];
int str[1111][1111],stlb[1111][1111];
void solve(){
    string ans;
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;++i){
        scanf("%s",s[i]);
    }
    
    for(int i=0;i<n;++i){
        str[i][0]=0;
        for(int j=1;j<=m;++j){
            str[i][j]=str[i][j-1]+(s[i][j-1]=='#');
        }
    }
    
    for(int i=0;i<m;++i){
        stlb[i][0]=0;
        for(int j=1;j<=n;++j){
            stlb[i][j]=stlb[i][j-1]+(s[j-1][i]=='#');
            //cout<<i<<' '<<j<<' '<<stlb[i][j]<<endl;
        }
        
        
    }
    
    
    int k;
    cin>>k;
    vector<pair<char,int> > q;
    getchar();
    for(int i=0;i<k;++i){
        char a;int b;
        scanf(" %c " INT,&a,&b);
        q.pb(pi(a,b));
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(s[i][j]=='.' || s[i][j]=='#')
                continue;
            int curi=i;
            int curj=j;
            bool ok=true;
            try{
                for(int l=0;l<k;++l){
                    switch(q[l].first){
                        case 'W':
                            if(curj<q[l].second){
                                throw string();
                            }
                            if(str[curi][curj-q[l].second]!=str[curi][curj]){
                                throw string();
                            }
                            curj-=q[l].second;
                            break;
                        case 'E':
                            if(curj+q[l].second>=m){
                                throw string();
                            }
                            if(str[curi][curj+q[l].second+1]!=str[curi][curj]){
                                throw string();
                            }
                            curj+=q[l].second;
                            break;
                        case 'N':
                            if(curi<q[l].second){
                                throw string();
                            }
                            if(stlb[curj][curi-q[l].second]!=stlb[curj][curi]){
                                throw string();
                            }
                            curi-=q[l].second;
                            break;
                            
                        case 'S':
                            if(curi+q[l].second>=n){
                                throw string();
                            }
                            if(stlb[curj][curi+q[l].second+1]!=stlb[curj][curi]){
                                throw string();
                            }
                            curi+=q[l].second;
                            break;
                    }
                }
            }
            catch(string a){
                ok=false;
            }
            if(ok)
                ans+=s[i][j];
        }
    }
    
    if(ans.length()){
        sort(ans.begin(),ans.end());
        cout<<ans;
    }
    else
        cout<<"no solution";
    
}