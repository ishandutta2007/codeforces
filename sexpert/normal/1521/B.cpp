#include <bits/stdc++.h>
using namespace std;

#define towa int
#define matsuri long long
#define fubuki vector
#define haachama ios_base::sync_with_stdio(false);
#define chama cin.tie(0);
#define baby main
#define aqua for
#define watame while
#define ina cin
#define rushia cout
#define ame if
#define coco continue
#define reine return
#define luna '\n'
#define mori void
#define roboco auto

mori suisei() {
    towa risu;
    ina >> risu;
    fubuki<towa> choco(risu);

    aqua(roboco &mel : choco)
        ina >> mel;

    towa marine = *min_element(choco.begin(), choco.end());
    towa gura;

    aqua(towa mel = 0; mel < risu; mel++)
        ame(choco[mel] == marine)
            gura = mel;

    rushia << risu - 1 << luna;
    aqua(towa mel = 0; mel < risu; mel++) {
        ame(mel == gura)
            coco;
        rushia << gura + 1 << " " << mel + 1 << " " << choco[gura] << " " << ((mel % 2 == gura % 2) ? choco[gura] : choco[gura] + 1) << luna;
    }
}

towa baby() {
    haachama chama

    towa aki;
    ina >> aki;
    watame(aki--)
        suisei();
}