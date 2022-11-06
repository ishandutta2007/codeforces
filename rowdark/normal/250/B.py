n = int(raw_input())
for test in range(0, n):
    a = ["0000" for i in range(0, 8)]
    s = raw_input().split(":")
    now = 0
    for i in range(0, len(s)):
        if s[i] == "":
            while 8 - now > len(s) - i:
                now += 1
            if 8 - now < len(s) - i:
                continue
        a[now] = s[i]
        while len(a[now]) < 4:
            a[now] = "0" + a[now]
        now += 1
    output = a[0]
    for i in range(1, 8):
        output += ":" + a[i]
    print(output)