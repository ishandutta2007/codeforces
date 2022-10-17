#include <iostream>
#include <unordered_set>
using namespace std;

int N, L, X, Y, M;

int inp[100005];
unordered_set<int> marks;

int main(){
    cin >> N >> L >> X >> Y;

    for(int i=0; i<N; i++){
        cin >> inp[i];
        marks.insert(inp[i]);
    }

    bool FX = false, FY = false;

    for(int i=0; i<N; i++){
        if(marks.count(inp[i] + X)) FX = true;
        if(marks.count(inp[i] + Y)) FY = true;
    }

    if(FX && FY){
        cout << 0 << endl;
        return 0;
    }

    for(int i=0; i<N; i++)
        for(int dir=-1; dir<=1; dir+=2){
            {
                bool TFX = FX, TFY = FY;
                int new_point = inp[i] + dir * X;
                if(new_point < 0 || new_point > inp[N-1]);
                else{
                    if(marks.count(new_point + Y)) TFY = true;
                    if(marks.count(new_point - Y)) TFY = true;

                    if(TFY){
                        cout << 1 << endl << new_point << endl;
                        return 0;
                    }
                }
            }
            {
                bool TFX = FX, TFY = FY;
                int new_point = inp[i] + dir * Y;
                if(new_point < 0 || new_point > inp[N-1]);
                else{
                    if(marks.count(new_point + X)) TFX = true;
                    if(marks.count(new_point - X)) TFX = true;

                    if(TFX){
                        cout << 1 << endl << new_point << endl;
                        return 0;
                    }
                }
            }
        }

    cout << 2 << endl;
    cout << X << " " << Y << endl;
}