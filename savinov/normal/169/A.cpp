#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector <int> h;
    int n,a,b;
    cin >> n >> a >> b;
    int t;
    for (int i=0;i<n;i++)
    {
        cin >> t;
        h.push_back(t);
    }
    sort (h.begin(),h.end());
    if ((h[b]-h[b-1])!=0) cout << h[b]-h[b-1]; else cout << 0;


    return 0;

}