#include <bits/stdc++.h>

using namespace std;

int t, n;
int nexxt[500000];
int p[500000];
//int all;
int curl;

int fil(int ind, int lesserleft, int rightlim) {
    int maxi = 0;
    //cout << "fil(" << ind << "," << lesserleft << "," << rightlim << ")" << endl;
    //all++;
    //if (all > 95) return 0;
    if (ind >= rightlim) return 0;
    if (nexxt[ind] == -1) {
        p[ind] = lesserleft+1;
        maxi = p[ind];
    //    cout << "p[" << ind << "]=" << p[ind] << endl;
    //    cout << "{" << endl;
        maxi = fil(ind+1, lesserleft+1, rightlim);
        if (maxi == -1)
            return -1;
        maxi = max(maxi, p[ind]);
    //    cout << "}" << endl;
        return maxi;
    }
    p[ind] = nexxt[ind]-ind+lesserleft;
    //cout << "p[" << ind << "]=" << p[ind] << endl;
      //  cout << "{" << endl;
    maxi = fil(ind+1, lesserleft, nexxt[ind]);
    //cout << "maxi " << maxi << endl;
    if (maxi >= p[ind] || maxi == -1) return -1;
    maxi = fil(nexxt[ind], lesserleft+nexxt[ind]-ind, rightlim);
    if (maxi == -1) return -1;
    maxi = max(maxi, p[ind]);
    //    cout << "}" << endl;
    return maxi;
}

int main()
{
    vector<int> rights;
    cin >> t;
    //all = 0;
    curl = 0;
    for (int qqqq = 0; qqqq < t; qqqq++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nexxt[curl+i];
            if (nexxt[curl+i] != -1)
                nexxt[curl+i] = nexxt[curl+i]+curl-1;
        }
        if(fil(curl, 0, curl+n) == -1)
            p[curl] = -1;
        curl += n;
        rights.push_back(n);
    }
    int inde = 0;
    int curr;
    curl = 0;
    while (inde < rights.size()) {
        curr = rights[inde];
        if (p[curl] == -1)
            cout << "-1";
        else
            for (int i = curl; i < curl+curr; i++) {
                cout << p[i] << " ";
            }
        cout << endl;
        curl += curr;
        inde++;
    }
    return 0;
}