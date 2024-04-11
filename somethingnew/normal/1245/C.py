mod = 10 ** 9 + 7
def count(s, num):
    if s != "u" and s != "n":
        return 1
    lst = [1 for i in range(num+1)]
    for i in range(2,num+1):
        lst[i] = lst[i-1] + lst[i-2]
        lst[i] %= mod
    return lst[-1]
st = input()
ans = 1
howelem = 0
lastelem = st[0]
for i in st:
    if i == "m" or i == "w":
        print(0)
        exit()
    if lastelem == i:
        howelem += 1
    else:
        ans *= count(lastelem, howelem)
        lastelem = i
        howelem = 1
        ans %= mod
ans *= count(lastelem, howelem)
ans %= mod
print(ans)