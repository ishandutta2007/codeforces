from math import log
predp=[1]
while predp[-1] < 10**9:
    predp.append(predp[-1]*2)
for t in range(int(input())):
    num = int(input())
    ans1 = int(log(num+1, 2)) - 1
    if 2 ** ans1 * 2 - 1 < num: ans1 += 1
    ans2 = []
    shag = ans1
    targetnow = num - shag - 1
    for i in range(ans1):
        ans2.append(min(targetnow//shag, predp[i]))
        targetnow -= min(targetnow//shag, predp[i]) * shag
        shag-=1
    print(ans1)
    print(*ans2)