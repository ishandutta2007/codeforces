#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string> v = {"Ac", "Md" ,"Al" ,"Hg" ,"Am" ,"Mo" ,"Sb" ,"Ns" ,"Ar" ,"Nd" ,"As" ,"Ne" ,"At" ,"Np" ,"Ba" ,"Nh" ,"Bk" ,"Ni" ,"Be" ,"Nb" ,"Bi" ,
                       "N" ,"Bh" ,"No" ,"B" ,"Og" ,"Br" ,"Os" ,"Cd" ,"O" ,"Ca" ,"Pd" ,"Cf" ,"P" ,"C" ,"Pt" ,"Ce" ,"Pu" ,"Cs" ,"Po" ,"Cl" ,"K" ,
                       "Cr" ,"Pr" ,"Co" ,"Pm" ,"Cn" ,"Pa" ,"Cu" ,"Ra" ,"Cm" ,"Rn" ,"Ds" ,"Re" ,"Db" ,"Rh" ,"Dy" ,"Rg" ,"Es" ,"Rb" ,"Er" ,"Ru" ,
                       "Eu" ,"Rf" ,"Fm" ,"Sm" ,"Fl" ,"Sc" ,"F" ,"Sg" ,"Fr" ,"Se" ,"Gd" ,"Si" ,"Ga" ,"Ag" ,"Ge" ,"Na" ,"Au" ,"Sr" ,"Hf" ,"S" ,"Hs" ,"Ta" ,"He" ,"Tc" ,"Ho" ,"Te" ,"H" ,"Ts" ,"In" ,"Tb" ,"I" ,"Tl" ,"Ir" ,"Th" ,"Fe" ,"Tm" ,"Kr" ,"Sn" ,"La" ,"Ti" ,"Lr"
            ,"W" ,"Pb" ,"U" ,"Li" ,"V" ,"Lv" ,"Xe" ,"Lu" ,"Yb" ,"Mg" ,"Y" ,"Mc" ,"Zn" ,"Mn" ,"Zr" ,"Mt"};	

//	vector<string> v = {"Ac",	"Md", "Al",	"Hg",	"Am",	"Mo",	"Sb",	"Ns",	"Ar",	"Nd",	"As",	"Ne", "At",	"Np", 	"Ba",	"Nh", "Bk",	"Ni", 	"Be",	"Nb", 	"Bi",	"N", "Bh", 	"No",	"B",	  "Og", "Br",	"Os",	"Cd",	"O",	"Ca",	"Pd", 	"Cf",	"P",	"C", 	"Pt",	"Ce",	"Pu", 	"Cs",	"Po", 	"Cl",	"K",	"Cr", 	"Pr",	"Co",	"Pm", 	"Cn",	"Pa",	"Cu",	"Ra", "Cm",	"Rn",	"Ds",	"Re", "Db",	"Rh",	"Dy",	"Rg", "Es",	"Rb", "Er",	"Ru", "Eu",	"Rf",	"Fm",	"Sm", "Fl",	"Sc",	"F",	"Sg", "Fr",	"Se",	"Gd",	"Si",	"Ga",	"Ag",	"Ge",	"Na",	"Au",	"Sr",	"Hf",	"S", "Hs", 	"Ta",	"He",	"Tc", "Ho",	"Te",	"H", "Tn",	"In",	"Tb",	"I","Tl",	"Ir",	"Th",	"Fe",	"Tm",	"Kr",	"Sn",	"La",	"Ti", "Lr",	"W", "Pb", 	"U",	"Li",	"V", "Lv", 	"Xe",	"Lu",	"Yb",	"Mg",	"Y",	"Mc", "Zn",	"Mn",	"Zr", "Mt"};
	cerr << v.size()<<'\n';
	string s;
	cin >>s;
	int n=s.size();
	vector<bool>dp(s.size()+1);
	dp[0]=true;
	for(int i=0;i<n;++i){
		 if (!dp[i])continue;
		 for(string x:v){
			 if (x.size() > 1 && 'a' <= x[1])
				 x[1] -= 32;
			 if (i+x.size() <= n && s.substr(i,x.size()) == x)
				 dp[i+x.size()]=true;
		 }
	}
	if (dp.back())
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}