#include <bits/stdc++.h>
using namespace std;

int n;
int curx, cury;
string res, s1, s2, res2;
typedef pair<int, int> P;

bool get_down(){
    printf("? %d %d %d %d\n", curx+1, cury, n, n);
    fflush(stdout);
    cin >> s2;
    return s2 == "YES";
}

bool get_left(){
    printf("? %d %d %d %d\n", 1, 1, curx, cury-1);
    fflush(stdout);
    cin >> s2;
    return s2 == "YES";

}

void go_right(){
    res.push_back('R');
    cury ++;
}

void go_down(){
    res.push_back('D');
    curx ++;
}

int main() {
    cin >> n;
    curx = cury = 1;
    while(curx + cury < n + 1){
        if(get_down()) go_down();
        else go_right();

    }
    curx = cury = n;
    while(curx + cury > n + 1){
        if(get_left()) res2.push_back('R'), cury--;
        else res2.push_back('D'), curx--;
    }
    reverse(res2.begin(), res2.end());
    cout << "! " << res + res2 << endl;
    fflush(stdout);
}