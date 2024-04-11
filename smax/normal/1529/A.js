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
        let i = 0;
        while (i < n && a[0] == a[i])
            i++;
        console.log(n - i);
    }
}