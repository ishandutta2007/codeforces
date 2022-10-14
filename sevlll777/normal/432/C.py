n = int(input())
ar = list(map(int, input().split()))
x = 10 ** 5 + 3
seva_nahui_esli_ne_paidet_tebe_pizda = [True] * x
seva_nahui_esli_ne_paidet_tebe_pizda[1] = False
for i in range(2, x):
    if seva_nahui_esli_ne_paidet_tebe_pizda[i]:
        for j in range(i * 2, x, i):
            seva_nahui_esli_ne_paidet_tebe_pizda[j] = False
ans = []
lol = [0] * (n + 1)
for i in range(n):
    lol[ar[i]] = i


def kinda_swap(l, r):
    if l >= r:
        return
    len = r - l + 1
    if seva_nahui_esli_ne_paidet_tebe_pizda[len]:
        ar[l], ar[r] = ar[r], ar[l]
        ans.append([l + 1, r + 1])
        return
    if len % 2 == 0:
        kinda_swap(l, l + 1)
        kinda_swap(l + 1, r)
        kinda_swap(l, l + 1)
        return
    for s in range(2, len + 1):
        if seva_nahui_esli_ne_paidet_tebe_pizda[s] and seva_nahui_esli_ne_paidet_tebe_pizda[r - l - s + 1 + 1]:
            kinda_swap(l, l + s - 1)
            kinda_swap(l + s - 1, r)
            kinda_swap(l, l + s - 1)
            return


for i in range(1, n):
    x = lol[i]
    lol[ar[x]] = i - 1
    lol[ar[i - 1]] = x
    kinda_swap(i - 1, x)
print(len(ans))
for elem in ans:
    print(elem[0], elem[1])