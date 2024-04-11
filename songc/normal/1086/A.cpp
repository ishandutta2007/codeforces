#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int M[1010][1010];
int Ax, Ay, Bx, By, Cx, Cy;
int Min=1234567890, Mx, My;

set<pii> P;

int main(){
    scanf("%d %d", &Ax, &Ay);
    scanf("%d %d", &Bx, &By);
    scanf("%d %d", &Cx, &Cy);
    for (int i=0; i<=1000; i++) for (int j=0; j<=1000; j++){
        if (abs(Ax-i)+abs(Ay-j)+abs(Bx-i)+abs(By-j)+abs(Cx-i)+abs(Cy-j) < Min){
            Min = abs(Ax-i)+abs(Ay-j)+abs(Bx-i)+abs(By-j)+abs(Cx-i)+abs(Cy-j);
            Mx = i, My = j;
        }
    }

    if (Mx <= Ax) {
        for (int i=Mx; i<=Ax; i++) P.insert(pii(i, My));
        if (My <= Ay) for (int i=My; i<=Ay; i++) P.insert(pii(Ax, i));
        else for (int i=My; i>=Ay; i--) P.insert(pii(Ax, i));
    }
    else {
        for (int i=Ax; i<=Mx; i++) P.insert(pii(i, Ay));
        if (Ay <= My) for (int i=Ay; i<=My; i++) P.insert(pii(Mx, i));
        else for (int i=Ay; i>=My; i--) P.insert(pii(Mx, i));
    }

    if (Mx <= Bx) {
        for (int i=Mx; i<=Bx; i++) P.insert(pii(i, My));
        if (My <= By) for (int i=My; i<=By; i++) P.insert(pii(Bx, i));
        else for (int i=My; i>=By; i--) P.insert(pii(Bx, i));
    }

    else {
        for (int i=Bx; i<=Mx; i++) P.insert(pii(i, By));
        if (By <= My) for (int i=By; i<=My; i++) P.insert(pii(Mx, i));
        else for (int i=By; i>=My; i--) P.insert(pii(Mx, i));
    }

    if (Mx <= Cx) {
        for (int i=Mx; i<=Cx; i++) P.insert(pii(i, My));
        if (My <= Cy) for (int i=My; i<=Cy; i++) P.insert(pii(Cx, i));
        else for (int i=My; i>=Cy; i--) P.insert(pii(Cx, i));
    }
    else {
        for (int i=Cx; i<=Mx; i++) P.insert(pii(i, Cy));
        if (Cy <= My) for (int i=Cy; i<=My; i++) P.insert(pii(Mx, i));
        else for (int i=Cy; i>=My; i--) P.insert(pii(Mx, i));
    }

    printf("%d\n", P.size());
    for (pii it : P) printf("%d %d\n", it.first, it.second);

    return 0;
}