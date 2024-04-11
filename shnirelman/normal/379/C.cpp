#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int> > a(n, make_pair(0, 0));
    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        a[i].first = b;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    int b = a[0].first;
    for(int i = 0; i < n; i++){
        if(b <= a[i].first)b = a[i].first + 1;
        else {
            a[i].first = b;
            b++;
        }
    }

    for(int i = 0; i < n; i++)swap(a[i].first, a[i].second);

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++)cout << a[i].second << ' ';

}