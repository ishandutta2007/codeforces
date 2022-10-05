n = input()
s = input()
zcolv = 0
for i in s:
    if i == "?":
        zcolv += 1
a = 0
ab = 0
mod = 10 ** 9 + 7
abc = 0
z = 0
zb = 0
az = 0
zz = 0
abz = 0
azc = 0
zbc = 0
azz = 0
zbz = 0
zzc = 0
zzz = 0
for i in s:
    if i == 'a':
        a += 1
    if i == 'b':
        ab += a
        zb += z
        zb %= mod
        ab %= mod
    if i == 'c':
        abc += ab
        zbc += zb
        zzc += zz
        azc += az
        zbc %= mod
        zzc %= mod
        azc %= mod
        abc %= mod
    if i == '?':
        abz += ab
        azz += az
        zbz += zb
        zzz += zz
        zz += z
        az += a
        z += 1
        abz %= mod
        azz %= mod
        zbz %= mod
        zzz %= mod
        zz %= mod
        az %= mod
        z %= mod
print((abc * pow(3, zcolv, mod) + (abz + azc + zbc) * pow(3, max(zcolv - 1, 0), mod) + (azz + zbz + zzc) * pow(3, max(zcolv - 2, 0), mod) + zzz * pow(3, max(zcolv - 3, 0))) % mod)