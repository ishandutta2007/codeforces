#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vector<int> suffix_array_construction(string s) {
  //s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    //sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  string s;
  cin>>n>>k>>s;
  vector<int> ord = suffix_array_construction(s);
  int ma=n;
  for(int j=n-1;ord[j]!=0;--j){
    //    cout<<ord[j]<<" greater than \n";
    ma = min(ma,ord[j]);
  }
  s=s.substr(0,ma);
  while(k>=ma){
    k-=ma;
    cout<<s;
  }
  cout<<s.substr(0,k);
  cout<<endl;
}