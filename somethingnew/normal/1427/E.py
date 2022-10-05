def pr(ans):
    print(len(ans))
    for i in ans:
        if i[0] == 1:
            print(i[1], "+", i[2])
        else:
            print(i[1], "^", i[2])
def fi2(st):
    return pow(2,st - 1)
def colv(num, fi, mod):
    return pow(num, fi - 1, mod)
step2 = set()
for i in range(64):
    step2.add(pow(2,i))
a = int(input())
ans = []
x = a
k = 0
for i in range(100):
    ans.append([1, x, a])
    y = x + a
    if y in step2:
        k = y
        break
    ans.append([2, x, y])
    x = y ^ x
    if x in step2:
        k = x
        break
if k == 1:
    pr(ans)
    exit()
stk = 0
kcopy = k
while kcopy % 2 == 0:
    stk += 1
    kcopy //= 2
step = fi2(stk)
num = colv(a, step, k) - 1
tosteps = [a]
for i in range(1, 64):
    ans.append([1, tosteps[-1], tosteps[-1]])
    t = tosteps[-1] * 2
    if t >= k:
        ans.append([2, t, k])
        t -= k
    tosteps.append(t)
an = a
for i in range(64):
    if num % 2 == 1:
        ans.append([1, an, tosteps[i]])
        an += tosteps[i]
        if an > k:
            ans.append([2, an, k])
            an -= k
    num //= 2
pr(ans)