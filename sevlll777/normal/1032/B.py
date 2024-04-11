s = input()
q = len(s)
strok = (q-1)//20 + 1
stolbtcov = (q-1)//strok+1
zvezd = strok*stolbtcov-q
a1=zvezd//strok
a2=zvezd%strok
print(strok, stolbtcov)
for j in range(strok-a2):
    print(s[stolbtcov * j:stolbtcov * (j + 1) - a1] + "*" * a1)
for i in range(strok-a2, strok):
    print(s[stolbtcov * i - a1*(strok-a2) - (i+a2-strok)*(a1+1):stolbtcov * (i + 1) - a1*(strok-a2) - 1 - (i+a2-strok)*(a1+1)] + "*" * (a1 + 1))