//#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
#include <stack>
using namespace std;
 
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()
 
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
 
const double pi=3.141592653589793;
const int INF=1000000000;
const int mod=1000000007;
 
vector<pair<int,int> > a;
 
 int len[100007];
 int S[100007];
 
int main(){
    string s;
    cin >> s;
    CLEAR(len);
    FOR(i,0,s.size()){
                      if (s[i] == '(') a.PB(MP(0,i));
                      if (s[i] == '[') a.PB(MP(1,i));
                      if (s[i] == ')' || s[i] == ']'){
                         int k = 0;
                         if (s[i] == ']') k = 1;
                         if (a.empty() || a.back().first != k) a.clear();
                         else{
                              len[a.back().second] = i; 
                              a.pop_back();   
                         }    
                      }                  
    }
    for(int i = 0 ; i < s.size() ; ++ i)
            if (len[i]){
                    int j = len[i] + 1;
                    while (j < s.size()){
                          if (!len[j]) break;
                          j = len[j] + 1;
                    }
                    len[i] = j - 1;
                    i = j;
    }
    S[0] = 0;
    FOR(i,1,s.size() + 1){
                   S[i] = S[i - 1];
                   if (s[i - 1] == '[') S[i]++;                
    }
    int id;
    int M = 0;
    //FOR(i,0,s.size())
    //                 cout << len[i] << ' ';
    //cout << endl;
    FOR(i,0,s.size())
                     if (len[i]){
                        if (S[len[i] + 1] - S[i] > M){
                           M = S[len[i] + 1] - S[i];
                           id = i; 
                           //cout << id << ' ' << M << ' ' << S[len[i] + 1] << ' ' << S[i] << endl;            
                        }            
                 }
    cout << M << endl;
    if (M)
       FOR(i,id,len[id] + 1)
                        cout << s[i];
    //system("pause");
    return 0;
}