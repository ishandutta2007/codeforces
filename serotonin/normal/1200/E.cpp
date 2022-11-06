#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

vector <string> a;

void form_lps(string r, int lps[])
{
    lps[0]=0;
    int i=1, len=0;
    while(i<r.size()) {
        if(r[i]==r[len]) lps[i++]=++len;
        else if(!len) lps[i++]=0;
        else len=lps[len-1];
    }
}

int fnc(string s, string r)
{
    int z=s.size();
    int lps[z];
    form_lps(r, lps);

    int ans=0,i=0,j=0;
    while(i<z) {
        if(s[i]==r[j]) i++, j++;
        else if(!j) i++;
        else j=lps[j-1];
    }
    return j;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }

    for(int i=0, j=1; j<n; j++) {
        string x;
        int cut, zi=a[i].size(), zj=a[j].size();
        if(zi>zj) {
            for(int k=zi-zj; k<zi; k++) x+=a[i][k];
            cut=fnc(x,a[j]);
        }
        else {
            for(int k=0; k<zi; k++) x+=a[j][k];
            cut=fnc(a[i],x);
        }
        for(int k=cut; k<zj; k++) a[i]+=a[j][k];
    }

    cout << a[0];
}