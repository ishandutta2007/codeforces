#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<pair <int, int> > b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = make_pair(a[i], i);
    }

    sort(b.begin(), b.end());

    vector<int> s(n, 0);
    for(int i = 0; i < n; i++){
        int s1 = i;
        while(b[s1].first == b[i].first){
            s[b[i].second] = s1;
            i++;
        }

        i--;
    }

    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if(a[x] > a[y])s[x]--;
        else if(a[x] < a[y])s[y]--;
    }

    for(int i = 0; i < n; i++)cout << s[i] << ' ';
}