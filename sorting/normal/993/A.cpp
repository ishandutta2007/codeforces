#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x, y;

    Point(){}
};

Point sq_1[4];
Point sq_2[4];

int get_area(const Point &a, const Point &b, const Point &c){
    int answer = a.x * b.y + b.x * c.y + c.x * a.y
                -(a.x * c.y + b.x * a.y + c.x * b.y);

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 4; ++i)
        cin >> sq_1[i].x >> sq_1[i].y;
    for(int i = 0; i < 4; ++i)
        cin >> sq_2[i].x >> sq_2[i].y;

    for(int i = 0; i < 4; ++i){
        sq_1[i].x *= 4;
        sq_1[i].y *= 4;
        sq_2[i].x *= 4;
        sq_2[i].y *= 4;
    }

    for(int j = 0; j < 4; ++j){
        int area[4];
        for(int i = 0; i < 4; ++i){
            int nxt = (i + 1) % 4;

            area[i] = get_area(sq_1[i], sq_1[nxt], sq_2[j]);
        }

        sort(area, area + 4);

        if(area[0] == 0 || area[3] == 0){
            cout << "YES\n";
            return 0;
        }

        if((area[0] < 0) == (area[3] < 0)){
            cout << "YES\n";
            return 0;
        }
    }

    swap(sq_1, sq_2);

    for(int j = 0; j < 4; ++j){
        int area[4];
        for(int i = 0; i < 4; ++i){
            int nxt = (i + 1) % 4;

            area[i] = get_area(sq_1[i], sq_1[nxt], sq_2[j]);
        }

        sort(area, area + 4);

        if(area[0] == 0 || area[3] == 0){
            cout << "YES\n";
            return 0;
        }

        if((area[0] < 0) == (area[3] < 0)){
            cout << "YES\n";
            return 0;
        }
    }

    Point mid;
    mid.x = 0;
    mid.y = 0;
    for(int i = 0; i < 4; ++i){
        mid.x += sq_2[i].x;
        mid.y += sq_2[i].y;
    }

    mid.x /= 4;
    mid.y /= 4;


    int area[4];
    for(int i = 0; i < 4; ++i){
        int nxt = (i + 1) % 4;

        area[i] = get_area(sq_1[i], sq_1[nxt], mid);
    }

    sort(area, area + 4);

    if(area[0] == 0 || area[3] == 0){
        cout << "YES\n";
        return 0;
    }

    if((area[0] < 0) == (area[3] < 0)){
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}