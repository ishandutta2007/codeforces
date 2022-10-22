#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> P;

void query(int a, int b, set<P> &st){
    while(!st.empty() && st.begin()->first < a) st.erase(*st.begin());
    while(!st.empty() && st.rbegin()->first > b) st.erase(*st.rbegin());
}
    

int main()
{
    int n, m;
    cin >> n >> m;
    set<P> lf, rh;
    int last = 0;
    int pl[100005], pr[100005];
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        bool f = !lf.empty(), g = !rh.empty();
        if(f || i == 0) rh.insert(P(last, i));
        if(g || i == 0) lf.insert(P(last, i));
        last = k;
        int al, bl, ar, br;
        cin >> al >> bl >> ar >> br;
        if(al > k || bl < k) lf.clear();
        else query(ar, br, lf);
        if(ar > k || br < k) rh.clear();
        else query(al, bl, rh);
        if(!lf.empty()) pl[i + 1] = lf.begin()->second;
        else pl[i + 1] = 0;
        if(!rh.empty()) pr[i + 1] = rh.begin()->second;
        else pr[i + 1] = 0;
    }
    if(lf.empty() && rh.empty()){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    bool l = true;
    if(lf.empty()) l = false;
    int k = n;
    int ans[100005];
    while(k > 0){
        int t;
        if(l) t = pl[k];
        else t = pr[k];
        l = !l;
        for(int i = t; i < k; i++) ans[i] = l;
        k = t;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}