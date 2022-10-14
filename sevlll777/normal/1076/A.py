n = int(input())
s = input()
fl = 1
kley = ""
for t in range(n-1):
    if fl and s[t] > s[t+1]:
        fl = 0
    else:
        kley += s[t]
if not fl:
    kley += s[-1]
print(kley)