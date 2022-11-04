import sys
import random
normal = ["great!","don't think so","cool","not bad","don't touch me!"]
grumpy = ["don't even","are you serious?","worse","terrible","go die in a hole","no way"]
result = "no"
while True:
    print random.randint(0, 9)
    sys.stdout.flush()
    result = raw_input().strip().lower()
    if result in normal:
        print "normal"
        break
    elif result in grumpy:
        print "grumpy"
        break
sys.stdout.flush()