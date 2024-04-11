n = int(input())
A = list(map(int, input().split()))
hod = {}
fl = 1
for i in A:
    if i not in hod:
        hod[i] = 0
    hod[i] += 1
for k in hod:
    if hod[k] % 2:
        print('Conan')
        fl = 0
        break
if fl:
    print('Agasa')