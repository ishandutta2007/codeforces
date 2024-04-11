#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PP;

int main()
{
    int n, k;
    cin >> n >> k;
    int l[200005], r[200005];
    PP pp[200005];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &l[i], &r[i]);
        pp[i] = PP(P(l[i], r[i]), i);
    }
    sort(pp, pp + n);
    vector<int> v;
    set<P> st;
    for(int i = 0; i < n; i++){
        if(i < k){
            st.insert(P(pp[i].first.second, pp[i].second));
            continue;
        }
        if(pp[i].first.first <= st.begin() -> first){
            st.insert(P(pp[i].first.second, pp[i].second));
            auto itr = st.end();
            itr--;
            v.push_back(itr -> second);
            st.erase(itr);
        }
        else{
            auto itr = st.lower_bound(P(pp[i].first.first, -1));
            itr--;
            st.erase(itr);
            st.insert(P(pp[i].first.second, pp[i].second));
        }
    }
    cout << (int)v.size() << endl;
    for(int x : v) cout << x + 1 << " ";
    cout << endl;
}