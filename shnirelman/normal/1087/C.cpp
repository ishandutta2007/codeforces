#include <bits/stdc++.h>

using namespace std;

set<pair<int, int> > ANS(int a0, int b0, int a1, int b1, int a2, int b2){

    set<pair<int, int> > s;

    for(int i = a0; i != a1; i += (a0 > a1 ? -1 : 1))s.insert({i, b0});//cout << i << ' ' << b[0];
    for(int i = b0; i != b1; i += (b0 > b1 ? -1 : 1))s.insert({a1, i});//cout << a[1] << ' ' << i;
    for(int i = a2; i != a1; i += (a2 > a1 ? -1 : 1))s.insert({i, b2});//cout << i << ' ' << b[2];
    for(int i = b2; i != b1; i += (b2 > b1 ? -1 : 1))s.insert({a1, i});//cout << a[1] << ' ' << i;

    s.insert({a1, b1});

    return s;
    //int res = abs(a1 - a2) + abs(b1 - b2) + abs(a3 - a2) + abs(b2 + b3);
    //return abs;
}

int main(){
    vector<int> a(3), b(3);
    for(int i = 0; i < 3; i++)cin >> a[i] >> b[i];

    set<pair<int, int> > ans1 = ANS(a[0], b[0], a[1], b[1], a[2], b[2]);
    set<pair<int, int> > ans2 = ANS(a[1], b[1], a[2], b[2], a[0], b[0]);
    set<pair<int, int> > ans3 = ANS(a[2], b[2], a[0], b[0], a[1], b[1]);

    if(ans1.size() <= ans2.size() && ans1.size() <= ans3.size()){
        cout << ans1.size() << endl;
        for(set<pair<int, int> >::iterator it = ans1.begin(); it != ans1.end(); it++)
            cout << it -> first << ' ' << it -> second << endl;
    }
    else if(ans2.size() <= ans1.size() && ans2.size() <= ans3.size()){
        cout << ans2.size() << endl;
        for(set<pair<int, int> >::iterator it = ans2.begin(); it != ans2.end(); it++)
            cout << it -> first << ' ' << it -> second << endl;
    }
    else{
        cout << ans3.size() << endl;
        for(set<pair<int, int> >::iterator it = ans3.begin(); it != ans3.end(); it++)
            cout << it -> first << ' ' << it -> second << endl;

    }

    /*
    cnt1 = cnt(a[0], b[0], a[1], b[1], a[2], b[2]);
    cnt2 = cnt(a[1], b[1], a[2], b[2], a[0], b[0]);
    cnt3 = cnt(a[2], b[2], a[0], b[0], a[1], b[1]);
    */

    /*
    if(cnt1 <= cnt2 && cnt1 <= cnt3){
        cout << cnt1 << endl;
        for(int i = a[0]; i != a[1]; i += (a[0] > a[1] ? -1 : 1))cout << i << ' ' << b[0];
        for(int i = b[0]; i != b[1]; i += (b[0] > b[1] ? -1 : 1))cout << a[1] << ' ' << i;
        for(int i = a[2]; i != a[1]; i += (a[2] > a[1] ? -1 : 1))cout << i << ' ' << b[2];
        for(int i = b[2]; i != b[1]; i += (b[2] > b[1] ? -1 : 1))cout << a[1] << ' ' << i;

    }
    else if(cnt2 <= cnt1 && cnt2 <= cnt3){
        for(int i = a[0]; i != a[1]; i += (a[0] > a[1] ? -1 : 1))cout << i << ' ' << b[0];
        for(int i = b[0]; i != b[1]; i += (b[0] > b[1] ? -1 : 1))cout << a[1] << ' ' << i;
        for(int i = a[0]; i != a[1]; i += (a[0] > a[1] ? -1 : 1))cout << i << ' ' << b[0];
        for(int i = b[0]; i != b[1]; i += (b[0] > b[1] ? -1 : 1))cout << a[1] << ' ' << i;
    }
    else{
        for(int i = a[0]; i != a[1]; i += (a[0] > a[1] ? -1 : 1))cout << i << ' ' << b[0];
        for(int i = b[0]; i != b[1]; i += (b[0] > b[1] ? -1 : 1))cout << a[1] << ' ' << i;
        for(int i = a[0]; i != a[1]; i += (a[0] > a[1] ? -1 : 1))cout << i << ' ' << b[0];
        for(int i = b[0]; i != b[1]; i += (b[0] > b[1] ? -1 : 1))cout << a[1] << ' ' << i;

    }
    */
}