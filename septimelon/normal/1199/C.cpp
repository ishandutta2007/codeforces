#include <bits/stdc++.h>

#define MAX 1000000007

using namespace std;

typedef pair<int,int> pii;

int main()
{
    int n, I;
    cin >> n >> I;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int curp = 0;
    vector<pii> an;
    an.push_back(pii(a[0], 1));
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            an[curp].second++;
        }
        else {
            an.push_back(pii(a[i], 1));
            curp++;
        }
    }
    int logmaxk = 0, maxk = 1;
    while (n * logmaxk <= 8 * I) {
        if (maxk >= n) {
            cout << "0" << endl;
            return 0;
        }
        logmaxk++;
        maxk *= 2;
    }
    logmaxk--;
    maxk /= 2;
    //cout << maxk << endl;
    int curil, curir, curpostr;
    int minpostr;
    curil = 0;
    curir = maxk;
    curpostr = 0;
    for (int i = curir; i < an.size(); i++)
        curpostr += an[i].second;
    minpostr = curpostr;
    while (curir < an.size()) {
        curpostr = curpostr - an[curir].second + an[curil].second;
        curil++;
        curir++;
        minpostr = min(minpostr, curpostr);
    }
    cout << minpostr << endl;
    return 0;
}