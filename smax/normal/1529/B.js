const rl = require("readline").createInterface({
    input: process.stdin,
    output: process.stdout
});

let lines = [];
let lineIdx = 0;

rl.on("line", line => {
    lines.push(line);
});

rl.on("close", () => {
    main();
});

function readLine() {
    return lines[lineIdx++];
}

function main() {
    let t = +readLine();
    while (t--) {
        let n = +readLine();
        let a = readLine().split(' ').map(x => +x).sort((x, y) => x - y);
        let diff = Infinity;
        let hasPos = false;
        let ret = 0;
        for (let i=0; i<n; i++) {
            if (a[i] <= 0) {
                ret++;
                if (i > 0)
                    diff = Math.min(diff, a[i] - a[i-1]);
            } else if (diff >= a[i] && !hasPos) {
                ret++;
                hasPos = true;
            }
        }
        console.log(ret);
    }
}