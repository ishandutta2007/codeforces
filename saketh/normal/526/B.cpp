#include <iostream>
using namespace std;

int D;
int l[3000];

pair<int, int> go(int loc){
    if(loc >= (1<<D))
        return make_pair(0, 0);

    pair<int, int> left = go(2*loc);
    pair<int, int> right = go(2*loc+1);

    left.first += l[2*loc];
    right.first += l[2*loc+1];

    int res = max(left.first, right.first);
    int cost = res - min(left.first, right.first);
    return make_pair(res, cost + left.second + right.second);
}

int main(){
    cin >> D;
    for(int i=2; i<(1<<(D+1)); i++)
        cin >> l[i];

    cout << go(1).second << endl;
}