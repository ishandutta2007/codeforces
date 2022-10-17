#include <bits/stdc++.h>
using namespace std;

#define LONG first.first
#define SHORT first.second

void fail() {
    cout << -1 << endl;
    exit(0);
}

string let = "ABC";
pair<pair<int, int>, char> rect[3];

void attempt(int H, int W) {
    if (rect[1].LONG != rect[2].LONG) return;
    if (W + rect[1].LONG != H) return;
    if (rect[1].SHORT + rect[2].SHORT != H) return;

    cout << H << "\n";
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cout << rect[0].second;

        for (int j = W; j < H; j++) {
            if (i < rect[1].SHORT) cout << rect[1].second;
            else cout << rect[2].second;
        }

        cout << "\n";
    }
    exit(0);
}

char grid[128][128];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (int i = 0; i < 3; i++) {
        cin >> rect[i].LONG;
        cin >> rect[i].SHORT;
        rect[i].second = let[i];

        if (rect[i].LONG < rect[i].SHORT) {
            swap(rect[i].LONG, rect[i].SHORT);
        }
    }        

    sort(rect, rect + 3);
    reverse(rect, rect + 3);

    int H = rect[0].LONG;
    int W = rect[0].SHORT;

    if (rect[1].LONG == H) {
        if (rect[2].LONG != H) fail();

        W += rect[1].SHORT + rect[2].SHORT;

        if (W != H) fail();

        cout << H << "\n";
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (j < rect[0].SHORT) cout << rect[0].second;
                else if(j < rect[0].SHORT + rect[1].SHORT) cout << rect[1].second;
                else cout << rect[2].second;
            }
            cout << "\n";
        }

        return 0;
    }
    else {
        attempt(H, W); // both normal
        swap(rect[1].LONG, rect[1].SHORT);
        attempt(H, W); // 1 swapped
        swap(rect[2].LONG, rect[2].SHORT);
        attempt(H, W); // both swapped
        swap(rect[1].LONG, rect[1].SHORT);
        attempt(H, W); // 2 swapped

        fail();
    } 
}