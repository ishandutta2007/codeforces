#include <bits/stdc++.h>
using namespace std;

#define towa int
#define matsuri long long
#define fubuki vector
#define flare push_back
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
#define sora sort

mori suisei() {
    towa risu, anya;
    ina >> risu >> anya;
    fubuki<towa> pekora(anya + 1);

    fubuki<array<towa, 2>> moona;

    aqua(towa mel = 1; mel <= anya; mel++) {
        ina >> pekora[mel];
        moona.flare({pekora[mel], mel});
    }

    //aqua(roboco &[mel, choco] : moona)
    //    rushia << mel << " " << choco << luna;

    sora(moona.rbegin(), moona.rend());
    aqua(towa azki = 1; ;azki++) {
        ame(azki * azki - (azki / 2) * (azki / 2) < risu || azki * ((azki + 1)/2) < moona[0][0])
            coco;
        fubuki<array<towa, 2>> kanata;
        aqua(towa mel = 2; mel <= azki; mel += 2)
            aqua(towa choco = 1; choco <= azki; choco += 2)
                kanata.flare({mel, choco});

        aqua(towa mel = 1; mel <= azki; mel += 2)
            aqua(towa choco = 1; choco <= azki; choco += 2)
                kanata.flare({mel, choco});

        aqua(towa mel = 1; mel <= azki; mel += 2)
            aqua(towa choco = 2; choco <= azki; choco += 2)
                kanata.flare({mel, choco});

        fubuki<fubuki<towa>> iofi(azki, fubuki<towa>(azki));
        towa okayu = 0, korone = 0;
        aqua(roboco &[mel, choco] : kanata) {
            watame(okayu < moona.size() && korone >= moona[okayu][0]) {
                okayu++;
                korone = 0;
            }
            ame(okayu >= moona.size())
                ollie;
            iofi[mel - 1][choco - 1] = moona[okayu][1];
            korone++;
        }
        rushia << azki << luna;
        aqua(towa mel = 0; mel < azki; mel++) {
            aqua(towa choco = 0; choco < azki; choco++) {
                rushia << iofi[mel][choco] << " ";
            }
            rushia << luna;
        }
        reine;
    }
}

towa baby() {
    haachama chama

    towa aki;
    ina >> aki;
    watame(aki--)
        suisei();
}