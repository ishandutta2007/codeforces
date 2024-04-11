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
#define kiara else
#define coco continue
#define reine return
#define ollie break
#define luna '\n'
#define nanora endl
#define mori void
#define roboco auto

towa ayame(towa yagoo, towa korone, towa okayu, towa mio) {
    rushia << "? " << yagoo << " " << korone << " " << okayu << " " << mio << nanora;
    towa subaru;
    ina >> subaru;
    reine subaru;
}

mori suisei() {
    towa risu;
    ina >> risu;
    fubuki<towa> pekora(risu + 1);
    towa lamy = 1, botan = risu - 1;
    watame(lamy < botan) {
        towa nene = (lamy + botan + 1) / 2;
        ame(ayame(2, 1, 2, nene - 1) == nene - 1 || ayame(2, 2, 1, nene - 1) == nene - 1)
            botan = nene - 1;
        kiara
            lamy = nene;
    }

    towa polka;
    
    ame(ayame(1, 1, 2, lamy) > lamy) {
        pekora[1] = lamy;
        polka = 1;
    }
    kiara {
        pekora[2] = lamy;
        polka = 2;
    }

    fubuki<towa> miko;
    ame(lamy - 1 >= risu - lamy)
        miko = {2, 1};
    kiara
        miko = {1, 2};

    aqua(towa mel = 1; mel <= risu; mel++) {
        ame(pekora[mel])
            coco;
        aqua(towa shion = 0; shion < 2; shion++) {
            ame(miko[shion] == 1) {
                towa noel = ayame(1, polka, mel, risu - 1);
                ame(noel > lamy) {
                    pekora[mel] = noel;
                    ollie;
                }
            }
            kiara {
                towa noel = ayame(2, mel, polka, 1);
                ame(noel < lamy) {
                    pekora[mel] = noel;
                    ollie;
                }
            }
        }
    }

    rushia << "! ";
    aqua(towa mel = 1; mel <= risu; mel++)
        rushia << pekora[mel] << " ";
    rushia << nanora;
}

towa baby() {
    haachama chama

    towa aki;
    ina >> aki;
    watame(aki--)
        suisei();
}