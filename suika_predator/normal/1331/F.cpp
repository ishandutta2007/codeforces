#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
string tab[233]={"","H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};
char s[233];
int ok[233];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>(s+1);
	n=strlen(s+1);
	ok[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=118;j++)
		{
			if(tab[j].length()==1)
			{
				if(ok[i-1]&&tab[j][0]==s[i])
					ok[i]=1;
			}
			else
			{
				if(i>1&&ok[i-2]&&tab[j][0]==s[i-1]&&toupper(tab[j][1])==s[i])
					ok[i]=1;
			}
		}
	}
	cout<<(ok[n]?"YES":"NO")<<endl;
	return 0;
}