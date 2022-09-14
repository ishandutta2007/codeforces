'''import sys
a = []
for i in sys.stdin:
    if len(i) > 1:
        a.append(i.split()[0])
print(' '.join(a))'''

t = 'Ac Ag Al Am Ar As At Au B Ba Be Bh Bi Bk Br C Ca Cd Ce Cf Cl Cm Cn Co Cr Cs Cu Db Ds Dy Er Es Eu F Fe Fl Fm Fr Ga Gd Ge H He Hf Hg Ho Hs I In Ir K Kr La Li Lr Lu Lv Mc Md Mg Mn Mo Mt N Na Nb Nd Ne Nh Ni No Np O Og Os P Pa Pb Pd Pm Po Pr Pt Pu Ra Rb Re Rf Rg Rh Rn Ru S Sb Sc Se Sg Si Sm Sn Sr Ta Tb Tc Te Th Ti Tl Tm Ts U V W Xe Y Yb Zn Zr'
r = input()
m = set([i.upper() for i in t.split()])
n = len(r)
dp = [0] * (n + 2)
dp[0] = 1
for i in range(n):
    if not dp[i]:
        continue
    for j in range(1, 3):
        if r[i:i+j] in m:
            dp[i+j] = 1
if dp[n]:
    print('YES')
else:
    print('NO')