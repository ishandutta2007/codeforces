#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const char* elems[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts",
"Og"};

char s[15];
bool f[15];

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    //printf("%d", n);
    f[0] = true;
    for (int i = 1; s[i]; i++) {
        for (int e = 0; e < 118; e++) {
            if (strlen(elems[e]) == 1) {
                if (s[i] == elems[e][0]) f[i] = f[i] || f[i-1];
            } else {
                if (i == 1) continue;
                if (s[i] == toupper(elems[e][1]) && s[i-1] == elems[e][0]) f[i] = f[i] || f[i-2];
            }
        }
    }
    printf("%s", f[n] ? "YES" : "NO");
    return 0;
}