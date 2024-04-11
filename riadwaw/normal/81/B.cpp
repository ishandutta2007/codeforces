#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
void solve(){
    char a[300];
    cin.getline(a,300);
    string s(a);
    enum {DIGIT,SPACE,DOTS,ZAP} was=DIGIT,here;
    string ans;
    for(int i=0;i<s.length();++i){
        if(s[i]<='9' && s[i]>='0')
            here=DIGIT;
        else if(s[i]==' ')
            here=SPACE;
        else if(s[i]==',')
            here=ZAP;
        else{
            here=DOTS;
            i+=2;
        }
        switch(was){
            case DIGIT:
                switch(here){
                    case DIGIT:
                        ans+=s[i];
                        break;
                    case ZAP:
                        ans+=string(", ");
                        was=ZAP;
                        break;
                    case DOTS:
                        if(i>2)
                            ans+=' ';
                        ans+=string("...");
                        was=DOTS;
                        break;
                    case SPACE:
                        ans+=' ';
                        was=SPACE;
                        break;
                }
                break;
            case SPACE:
                switch(here){
                    case DIGIT:
                        ans+=s[i];
                        was=DIGIT;
                        break;
                    case ZAP:
                        ans.resize(ans.length()-1);
                        ans+=string(", ");
                        was=ZAP;
                        break;
                    case DOTS:
                        ans+=string("...");
                        was=DOTS;
                        break;
                }
                break;
            case ZAP:
                switch(here){
                    case DIGIT:
                        ans+=s[i];
                        was=DIGIT;
                        break;
                    case ZAP:
                        ans+=string(", ");
                        was=ZAP;
                        break;
                    case DOTS:
                        ans+=string("...");
                        was=DOTS;
                        break;
                }
                break;
            case DOTS:
                switch(here){
                    case DIGIT:
                        ans+=s[i];
                        was=DIGIT;
                        break;
                    case ZAP:
                        ans+=string(", ");
                        was=ZAP;
                        break;
                    case DOTS:
                        ans+=' ';
                        ans+=string("...");
                        break;
                    /*case SPACE:
                        ans+=' ';
                        was=SPACE;
                        break;*/
                }
                break;
        }
    }
    if(was==ZAP)
        ans.resize(ans.length()-1);
    cout<<ans;
}