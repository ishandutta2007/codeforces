#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<string, double> P;

int n;
P ps[100050];
string str = "";

bool cmp(P a, P b){
    return a.second > b.second;
}

int main(){
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin , str);
        int s = 0, h = 0;
        for(int j = 0; j < str.length(); j++){
            if(str[j] == 's') s++;
            else h ++;
        }
        ps[i].first = str;
        ps[i].second = (h == 0) ? 10000000 : (s == 0 ? -1: (double)s / h);
        //cout << ps[i].second << endl;
    }
    sort(ps,ps+n,cmp);
    str = "";
    for(int i = 0; i < n; i++){
        str += ps[i].first;
    }
    ll res = 0;
    ll sn = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == 's') sn++;
        else res += sn;
    }
    //cout << str;
    cout << res;

}