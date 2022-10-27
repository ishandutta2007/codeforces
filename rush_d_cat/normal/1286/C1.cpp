#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N=100+10;
int n;
multiset<string> s[2];
string pars(char str[], int l) {
    sort(str,str+l);
    string res="";
    for(int i=0;str[i];i++)res=res+str[i];
    return res;
}
void ask(int id,int l,int r){
    printf("? %d %d\n", l,r);
    fflush(stdout);
    int len=(r-l+1),tot=len*(len+1)/2;
    for(int i=1;i<=tot;i++){
        char str[N];
        scanf("%s",str);
        int l = strlen(str);
        s[id].insert(pars(str,l));
    } 
}
bool cmp(string a, string b) {
    return a.size() < b.size();
}
int main() {
    scanf("%d",&n);
    if(n==1) {
        printf("? 1 1\n"); fflush(stdout);
        char s[2]; scanf("%s",s);
        printf("! %s\n", s); fflush(stdout);
        return 0;
    }
    ask(0,1,n);
    ask(1,2,n);
    for(auto p:s[1]){
        s[0].erase(s[0].find(p));
    } 
    vector<string> v;
    for(auto p:s[0]) v.push_back(p);
    sort(v.begin(),v.end(),cmp);
    string ans="";
    ans += v[0];
    int cnt[30] = {0}; cnt[ans[0]-'a']++;
    for(int i=1;i<v.size();i++){
        int tmp[30] = {0};
        for(int j=0;j<v[i].size();j++){
            tmp[v[i][j]-'a']++;
        }
        for(int j=0;j<26;j++){
            if(tmp[j]>cnt[j]){
                cnt[j]++; ans+=(char)('a'+j);
                break;
            }
        }
    }
    printf("! ");
    for(int i=0;i<ans.size();i++)printf("%c", ans[i]);
    printf("\n"); fflush(stdout);
}