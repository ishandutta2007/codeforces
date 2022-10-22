#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, P> PP;

int main()
{
    int n;
    cin >> n;
    int x[50003], y[50003], z[50003];
    PP p[50003];
    set<PP> st;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
        p[i] = PP(P(x[i], y[i]), P(z[i], i + 1));
        st.insert(p[i]);
    }
    bool removed[50003];
    fill(removed, removed + n, false);
    auto itr = st.begin();
    while(itr != st.end()){
        PP now = *itr;
        itr++;
        st.erase(now);
        auto nitr = st.lower_bound(PP(P(itr -> first.first, now.first.second), P(-200000000, 0)));
        if(nitr == st.end() || nitr -> first.first != itr -> first.first){
            nitr--;
        }
        auto nnitr = st.lower_bound(PP(nitr -> first, P(now.second.first, 0)));
        if(nnitr == st.end() || nnitr -> first.first != itr -> first.first || nnitr -> first.second != nitr -> first.second){
            nnitr--;
        }
        cout << now.second.second << " " << nnitr -> second.second << endl;
        if(nnitr == itr) itr++;
        st.erase(nnitr);
    }
}